require('../models/Data');

var mongoose = require('mongoose'),
    Data = mongoose.model('Data');


var Datas = {
    index: function (req, res) {

        Data.find({}, function (err, Datas) {
            if (err) throw err;

            // object of all the DATAS
            console.log(Datas);
        });

        res.render('Datas/index', {
            title: 'home',
            active: 'account'
        });
    },
    create: function (req, res) {

        var u = new Data({
            name: req.body.name,
            firstName: req.body.firstname,
            email: req.body.email
        });

        u.save(function (err) {
            if (err) {
                console.log('Data inserted');
            }
        });

        res.json(u);
    },
    update: function (req, res) {

        Data.findById(req.params.id, function (err, Data) {
            if (err) throw err;

            // change the DATAS location
            Data.name = 'Josay';

            // save the DATA
            Data.save(function (err) {
                if (err) throw err;

                console.log('Data successfully updated!');
            });

        });

        res.render('Datas/index', {
            title: 'home',
            active: 'account'
        });
    },
    delete: function (req, res) {

        Data.findById(req.params.id, function (err, Data) {
            if (err) throw err;

            // delete him
            Data.remove(function (err) {
                if (err) throw err;

                console.log('Data successfully deleted!');
            });
        });

        res.render('Datas/index', {
            title: 'home',
            active: 'account'
        });
    }
};

module.exports = Datas;