$(document).ready(function() {
  console.log('Screen width:', $('#edge').width())
  $('#reset').prop('disabled', true).css('opacity', 0.5);

});


// Start the test
$(function() {
  $('#start').click(function() {
    $('#start').prop('disabled', true).css('opacity', 0.5);

    moveRight().pipe(moveLeft).pipe(moveRight).pipe(testComplete)

    setTimeout(function() {
      $('#reset').prop('disabled', false).css('opacity', 1.0);
    }, 4000);

  })
})

// Moves the test box right in 100 milliseconds with a 1 second delay
function moveRight() {
  var d = $.Deferred()
  console.log('Initiating test');

  setTimeout(function() {
    var move = '+=' + ($('#edge').width() - 100);;
    $('#test-box').animate({
      left: move
    }, 100);
    d.resolve();
  }, 1000);

  return d.promise()
}

// Moves the test box left in 100 milliseconds with a 1 second delay
function moveLeft() {
  var d = $.Deferred()

  setTimeout(function() {
    var move = '-=' + ($('#edge').width() - 100);
    $('#test-box').animate({
      left: move
    }, 100);
    d.resolve();
  }, 1000);

  return d.promise()
}

// Changes color of box to green
function testBegin() {

  setTimeout(function() {
    var div = document.getElementById('test-box');
    div.style.backgroundColor = '#98bf21';
  }, 200);
}

// Changes color of box to red
function testComplete() {

  setTimeout(function() {
    var div = document.getElementById('test-box');
    div.style.backgroundColor = '#f44242';
  }, 200);
}

// Reset the test
$(function() {
  $('#reset').click(function() {
    console.log('Resetting test');

    $('#start').prop('disabled', false).css('opacity', 1.0);

    moveLeft()
    setTimeout(testBegin, 200)
  })
})
