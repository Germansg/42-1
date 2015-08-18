angular.module('starter.controllers', [])

.controller('AppCtrl', function($scope, $ionicModal, $timeout) {

  // With the new view caching in Ionic, Controllers are only called
  // when they are recreated or on app start, instead of every page change.
  // To listen for when this page is active (for example, to refresh data),
  // listen for the $ionicView.enter event:
  //$scope.$on('$ionicView.enter', function(e) {
  //});

  // Form data for the login modal
  $scope.loginData = {};

  // Create the login modal that we will use later
  $ionicModal.fromTemplateUrl('templates/login.html', {
    scope: $scope
  }).then(function(modal) {
    $scope.modal = modal;
  });

  // Triggered in the login modal to close it
  $scope.closeLogin = function() {
    $scope.modal.hide();
  };

  // Open the login modal
  $scope.login = function() {
    $scope.modal.show();

  };

  // Perform the login action when the user submits the login form
  $scope.doLogin = function() {
    console.log('Doing login', $scope.loginData);

    // Simulate a login delay. Remove this and replace with your login
    // code if using a login system
    $timeout(function() {
      $scope.closeLogin();
    }, 1000);
  };
})

.controller('PlaylistsCtrl', function($scope) {
  $scope.playlists = [
    { name: 'A Delort', age: 24 },
    { name: 'G Sio', age: 19 },
    { name: 'V Germain', age: 32 },
    { name: 'L Perrin', age: 19 },
    { name: 'W Khazri', age: 22 },
    { name: 'N D Préville', age: 23 },
      { name: 'F Kamano', age: 21 },
      { name: 'F Diedhou', age: 21 },
      { name: 'A R Camara', age: 23 },
      { name: 'Lucas', age: 28 },
      { name: 'P Sané', age: 26 },
      { name: 'B Grougi', age: 24 },
      { name: 'I Cavaleiro', age: 19 },
      { name: 'F Ayité', age: 17 },
      { name: 'M Braithwait', age: 18 },
      { name: 'J Tavares', age: 33 },
      { name: 'B Silva', age: 31 },
      { name: 'C Julien', age: 29 },
  ];



        $scope.clickPredicateName = function(){
            $scope.orderByReverse = !$scope.orderByReverse;
            $scope.orderByPredicate = 'name';
        };

        $scope.clickPredicateAge = function(){
            $scope.orderByReverse = !$scope.orderByReverse;
            $scope.orderByPredicate = 'age';
        };
})

.controller('PlaylistCtrl', function($scope) {
        $scope.playlists = [
            { name: 'A Delort', age: 22 },
        ];
})

.controller('SearchCtrl', function($scope, $ionicPopup) {

        $scope.giveAlert = function () {
            var alertPopup = $ionicPopup.alert({
                title: 'Popup ?',
                template: "Popup !"
            });
        }
});