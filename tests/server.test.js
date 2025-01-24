const request = require('supertest');
const express = require('express');
const mysql = require('mysql');
const cors = require('cors');
const app = require('../server'); // Adjust the path as needed

describe('User API', () => {
    it('should register a new user', async () => {
        const res = await request(app)
            .post('./Signup')
            .send({ name: 'John Doe', email: 'john@example.com', password: 'password123' });
        expect(res.statusCode).toEqual(200);
        expect(res.body).toHaveProperty('insertId'); // Assuming you get an ID back
    });

    it('should log in an existing user', async () => {
        const res = await request(app)
            .post('./Login')
            .send({ email: 'john@example.com', password: 'password123' });
        expect(res.statusCode).toEqual(200);
        expect(res.body).toEqual('Success');
    });

    it('should fail to log in with wrong password', async () => {
        const res = await request(app)
            .post('/login')
            .send({ email: 'john@example.com', password: 'wrongpassword' });
        expect(res.statusCode).toEqual(200);
        expect(res.body).toEqual('Failed');
    });
});