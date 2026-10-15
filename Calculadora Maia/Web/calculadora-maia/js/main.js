// Listas con los 20 sellos Tzolkin y los 19 meses Haab
const TZOLKIN_NAMES = [
  "Imix'", "Ik'", "Ak'b'al", "K'an", "Chikchan", "Cimi", "Manik'", 
  "Lamat", "Muluk", "Oc", "Chuen", "Eb'", "B'en", "IX", "Men", 
  "C'ib'", "Cab'an", "Etz'nab'", "Cauac", "Ahau"
];

const HAAB_MONTHS = [
  "Pop", "Wo'", "Sip", "Sotz'", "Sek", "Xul", "Yaxk'in'", "Mol", 
  "Ch'en", "Yax", "Sak'", "Keh", "Mak", "K'ank'in", "Muwan", "Pax", 
  "K'ayab'", "Kumk'u", "Wayeb'"
];

// Cálculo del Día Juliano Número (JDN) desde fecha Gregoriana
function getJulianDayNumber(year, month, day) {
  let a = Math.floor((14 - month) / 12);
  let y = year + 4800 - a;
  let m = month + 12 * a - 3;
  return day + Math.floor((153 * m + 2) / 5) + 365 * y + Math.floor(y / 4) - Math.floor(y / 100) + Math.floor(y / 400) - 32045;
}

// Convertir JDN a fecha Tzolkin y Haab usando la correlación GMT (584283)
function convertToMaya(gregorianDateString) {
  const parts = gregorianDateString.split('-');
  const year = parseInt(parts[0], 10);
  const month = parseInt(parts[1], 10);
  const day = parseInt(parts[2], 10);

  const jdn = getJulianDayNumber(year, month, day);
  
  // Días transcurridos desde la época Maya GMT (11 de agosto de 3114 a.C.)
  const daysElapsed = jdn - 584283;

  // 1. Calendario Tzolkin (Ciclo de 260 días)
  const tzolkinNumber = ((daysElapsed + 3) % 13) + 1;
  let tzolkinNameIndex = (daysElapsed + 19) % 20;
  if (tzolkinNameIndex < 0) tzolkinNameIndex += 20;
  const tzolkinResult = `${tzolkinNumber} ${TZOLKIN_NAMES[tzolkinNameIndex]}`;

  // 2. Calendario Haab (Ciclo de 365 días)
  let haabDayInYear = (daysElapsed + 348) % 365;
  if (haabDayInYear < 0) haabDayInYear += 365;

  let monthIndex = Math.floor(haabDayInYear / 20);
  let dayInMonth = haabDayInYear % 20;

  let haabResult = "";
  if (monthIndex === 18) {
    haabResult = `${dayInMonth} Wayeb'`;
  } else {
    haabResult = `${dayInMonth} ${HAAB_MONTHS[monthIndex]}`;
  }

  return { tzolkin: tzolkinResult, haab: haabResult };
}

// Event Listeners de la interfaz
document.addEventListener('DOMContentLoaded', () => {
  const form = document.getElementById('maya-form');
  const dateInput = document.getElementById('gregorian-date');
  const resultsContainer = document.getElementById('results');
  const tzolkinOutput = document.getElementById('tzolkin-output');
  const haabOutput = document.getElementById('haab-output');

  // Establecer fecha de hoy como predeterminada
  const today = new Date().toISOString().split('T')[0];
  dateInput.value = today;

  form.addEventListener('submit', (e) => {
    e.preventDefault();
    const selectedDate = dateInput.value;
    
    if (selectedDate) {
      const mayaDate = convertToMaya(selectedDate);
      tzolkinOutput.textContent = mayaDate.tzolkin;
      haabOutput.textContent = mayaDate.haab;
      resultsContainer.classList.remove('hidden');
    }
  });
});