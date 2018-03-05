var orderCount = 0;

function takeOrder(topping, crustType) {
  orderCount = orderCount + 1;
  console.log('Order: ' + crustType + ' pizza topped with ' + topping);
}

function getSubTotal(itemCount) {
  return itemCount * 7.50;
}

function getTax() {
  return getSubTotal(orderCount) * 0.06;
}

function getTotal() {
  return getSubTotal(orderCount) + getTax();
}

takeOrder('bacon', 'thin crust');
takeOrder('pepperoni', 'stuffed crust');
takeOrder('extra cheese', 'deep dish');

console.log('Subtotal: $' + getSubTotal(orderCount).toFixed(2));
console.log('Tax: $' + getTax().toFixed(2));
console.log('Total: $' + getTotal());