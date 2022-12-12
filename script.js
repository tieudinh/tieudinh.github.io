window.onload = () => {
  document.querySelector(".js-st-bar").style.width = '70%';
  document.querySelector(".js-lvn-bar").style.width = '80%';
  document.querySelector(".js-dd-bar").style.width = '95%';

  const buttonPDF = document.querySelector(".js-to-pdf");
  buttonPDF.addEventListener('click', function() {
    buttonPDF.style.display = 'none';
    window.print();
    buttonPDF.style.display = 'block';
  })
};