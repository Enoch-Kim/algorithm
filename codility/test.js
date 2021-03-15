import React, { useState, useEffect } from 'react';

const USERS_URL = 'https://example.com/api/users';

export default function Table () {
    
    const [users, setUsers] = useState([]);
    const [maxPage, setMaxPage] = useState(0);
    const [curPage, setCurPage] = useState(0);
    const [loading, setLoading] = useState(true);

    useEffect(() => {
        fetchPage(0);
    }, [])

    const pageSize = 10;

    const fetchPage = (pageNum) => {
        setLoading(true);

        const url = USERS_URL + "?page="+pageNum;
        fetch(url)
            .then(res => res.json())
            .then(resJson => {
                setCurPage(pageNum);
                setMaxPage(parseInt(resJson.count/pageSize));
                setUsers(resJson.results);
                setLoading(false);
            })
            .catch(err => console.log(err));
    }

    const onClickPagenate = (pageNum) => {
        return () => {
            fetchPage(pageNum);
        }
    }

    return (
        <div>
        <table className="table">
            <thead>
            <tr>
                <th>ID</th>
                <th>First Name</th>
                <th>Last Name</th>
            </tr>
            </thead>
            <tbody>
                {
                    users.map(user => (
                        <tr key={user.id}>
                            <td>{user.id}</td>
                            <td>{user.firstName}</td>
                            <td>{user.lastName}</td>
                        </tr>
                    ))
                }
            </tbody>
        </table>
        <section className="pagination">
            <button className="first-page-btn" onClick={onClickPagenate(0)} disabled={loading || curPage==0}>first</button>
            <button className="previous-page-btn" onClick={onClickPagenate(curPage-1)} disabled={loading || curPage==0}>previous</button>
            <button className="next-page-btn" onClick={onClickPagenate(curPage+1)}  disabled={loading || curPage==maxPage}>next</button>
            <button className="last-page-btn" onClick={onClickPagenate(maxPage)}  disabled={loading || curPage==maxPage}>last</button>
        </section>
        </div>
    );
};
