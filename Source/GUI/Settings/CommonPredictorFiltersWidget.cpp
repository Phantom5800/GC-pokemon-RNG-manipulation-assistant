#include "CommonPredictorFiltersWidget.h"

#include <QFormLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>

#include "../GUICommon.h"

static constexpr int SpinBoxWidth = 40;

CommonPredictorFiltersWidget::CommonPredictorFiltersWidget(QWidget* parent) : QWidget(parent)
{
  QLabel* lblIvs = new QLabel(tr("Filter wanted predictions by\nthe following minimal IVs"));

  QLabel* lblHpIv = new QLabel(tr("HP: "));
  m_spnMinHpIv = new QSpinBox();
  m_spnMinHpIv->setMinimum(0);
  m_spnMinHpIv->setMaximum(31);
  m_spnMinHpIv->setValue(0);
  m_spnMinHpIv->setMaximumWidth(SpinBoxWidth);

  QLabel* lblAtkIv = new QLabel(tr("Attack: "));
  QHBoxLayout* atkMins = new QHBoxLayout;
  for (int i = 0; i < sizeof(m_spnMinAtkIv) / sizeof(m_spnMinAtkIv[0]); ++i)
  {
    m_spnMinAtkIv[i] = new QSpinBox();
    m_spnMinAtkIv[i]->setMinimum(0);
    m_spnMinAtkIv[i]->setMaximum(31);
    m_spnMinAtkIv[i]->setValue(0);
    m_spnMinAtkIv[i]->setMaximumWidth(SpinBoxWidth);
    atkMins->addWidget(m_spnMinAtkIv[i]);
  }

  QLabel* lblDefIv = new QLabel(tr("Defense: "));
  QHBoxLayout* defMins = new QHBoxLayout;
  for (int i = 0; i < sizeof(m_spnMinDefIv) / sizeof(m_spnMinDefIv[0]); ++i)
  {
    m_spnMinDefIv[i] = new QSpinBox();
    m_spnMinDefIv[i]->setMinimum(0);
    m_spnMinDefIv[i]->setMaximum(31);
    m_spnMinDefIv[i]->setValue(0);
    m_spnMinDefIv[i]->setMaximumWidth(SpinBoxWidth);
    defMins->addWidget(m_spnMinDefIv[i]);
  }

  QLabel* lblSpAtkIv = new QLabel(tr("Special Attack: "));
  QHBoxLayout* spAtkMins = new QHBoxLayout;
  for (int i = 0; i < sizeof(m_spnMinSpAtkIv) / sizeof(m_spnMinSpAtkIv[0]); ++i)
  {
    m_spnMinSpAtkIv[i] = new QSpinBox();
    m_spnMinSpAtkIv[i]->setMinimum(0);
    m_spnMinSpAtkIv[i]->setMaximum(31);
    m_spnMinSpAtkIv[i]->setValue(0);
    m_spnMinSpAtkIv[i]->setMaximumWidth(SpinBoxWidth);
    spAtkMins->addWidget(m_spnMinSpAtkIv[i]);
  }

  QLabel* lblSpDefIv = new QLabel(tr("Special Defense: "));
  QHBoxLayout* spDefMins = new QHBoxLayout;
  for (int i = 0; i < sizeof(m_spnMinSpDefIv) / sizeof(m_spnMinSpDefIv[0]); ++i)
  {
    m_spnMinSpDefIv[i] = new QSpinBox();
    m_spnMinSpDefIv[i]->setMinimum(0);
    m_spnMinSpDefIv[i]->setMaximum(31);
    m_spnMinSpDefIv[i]->setValue(0);
    m_spnMinSpDefIv[i]->setMaximumWidth(SpinBoxWidth);
    spDefMins->addWidget(m_spnMinSpDefIv[i]);
  }

  QLabel* lblSpeedIv = new QLabel(tr("Speed: "));
  QHBoxLayout* speedMins = new QHBoxLayout;
  for (int i = 0; i < sizeof(m_spnMinSpeedIv) / sizeof(m_spnMinSpeedIv[0]); ++i)
  {
    m_spnMinSpeedIv[i] = new QSpinBox();
    m_spnMinSpeedIv[i]->setMinimum(0);
    m_spnMinSpeedIv[i]->setMaximum(31);
    m_spnMinSpeedIv[i]->setValue(0);
    m_spnMinSpeedIv[i]->setMaximumWidth(SpinBoxWidth);
    speedMins->addWidget(m_spnMinSpeedIv[i]);
  }

  QLabel* lblHiddenPowerPower = new QLabel(tr("Minimum power of Hidden power: "));
  m_spnMinPowerHiddenPower = new QSpinBox();
  m_spnMinPowerHiddenPower->setMinimum(30);
  m_spnMinPowerHiddenPower->setMaximum(70);
  m_spnMinPowerHiddenPower->setValue(30);
  m_spnMinPowerHiddenPower->setMaximumWidth(SpinBoxWidth);

  QHBoxLayout* hiddenPowerPowerLayout = new QHBoxLayout;
  hiddenPowerPowerLayout->addWidget(lblHiddenPowerPower);
  hiddenPowerPowerLayout->addWidget(m_spnMinPowerHiddenPower);

  QFormLayout* IvInputLayout = new QFormLayout();
  IvInputLayout->setLabelAlignment(Qt::AlignRight);
  IvInputLayout->addRow(lblHpIv, m_spnMinHpIv);
  IvInputLayout->addRow(lblAtkIv, atkMins);
  IvInputLayout->addRow(lblDefIv, defMins);
  IvInputLayout->addRow(lblSpAtkIv, spAtkMins);
  IvInputLayout->addRow(lblSpDefIv, spDefMins);
  IvInputLayout->addRow(lblSpeedIv, speedMins);

  QGridLayout* naturesChkLayout = new QGridLayout;
  for (int i = 0; i < GUICommon::naturesStr.size(); i++)
  {
    QCheckBox* chk = new QCheckBox(GUICommon::naturesStr[i]);
    chk->setChecked(false);
    m_chkNatures.append(chk);
    naturesChkLayout->addWidget(chk, i / 4, i % 4);
  }

  m_naturesWidget = new QWidget;
  m_naturesWidget->setLayout(naturesChkLayout);
  m_naturesWidget->setEnabled(false);

  m_chkEnableNatureFilter = new QCheckBox(tr("Filter wanted predictions by nature"), this);
  connect(m_chkEnableNatureFilter, &QCheckBox::stateChanged, this,
          [=](int state) { m_naturesWidget->setEnabled(state == Qt::CheckState::Checked); });

  QGridLayout* typesChkLayout = new QGridLayout;
  for (int i = 0; i < GUICommon::typesStr.size(); i++)
  {
    QCheckBox* chk = new QCheckBox(GUICommon::typesStr[i]);
    chk->setChecked(false);
    m_chkHiddenPowerTypes.append(chk);
    typesChkLayout->addWidget(chk, i / 4, i % 4);
  }

  m_typesWidget = new QWidget;
  m_typesWidget->setLayout(typesChkLayout);
  m_typesWidget->setEnabled(false);

  m_chkEnableHiddenPowerTypeFilter =
      new QCheckBox(tr("Filter wanted predictions by hidden power type"), this);
  connect(m_chkEnableHiddenPowerTypeFilter, &QCheckBox::stateChanged, this,
          [=](int state) { m_typesWidget->setEnabled(state == Qt::CheckState::Checked); });

  QVBoxLayout* leftLayout = new QVBoxLayout;
  leftLayout->addWidget(lblIvs);
  leftLayout->addLayout(IvInputLayout);
  leftLayout->addSpacing(30);
  leftLayout->addLayout(hiddenPowerPowerLayout);
  leftLayout->addStretch();

  QVBoxLayout* rigthLayout = new QVBoxLayout;
  rigthLayout->addWidget(m_chkEnableNatureFilter);
  rigthLayout->addWidget(m_naturesWidget);
  rigthLayout->addWidget(m_chkEnableHiddenPowerTypeFilter);
  rigthLayout->addWidget(m_typesWidget);
  rigthLayout->addStretch();

  QHBoxLayout* mainLayout = new QHBoxLayout;
  mainLayout->addLayout(leftLayout);
  mainLayout->addSpacing(30);
  mainLayout->addLayout(rigthLayout);

  setLayout(mainLayout);
}

CommonPredictorFiltersWidget::~CommonPredictorFiltersWidget()
{
}

int CommonPredictorFiltersWidget::getMinHpIv() const
{
  return m_spnMinHpIv->value();
}

int CommonPredictorFiltersWidget::getMinAtkIv(int idx) const
{
  return m_spnMinAtkIv[idx]->value();
}

int CommonPredictorFiltersWidget::getMinDefIv(int idx) const
{
  return m_spnMinDefIv[idx]->value();
}

int CommonPredictorFiltersWidget::getMinSpAtkIv(int idx) const
{
  return m_spnMinSpAtkIv[idx]->value();
}

int CommonPredictorFiltersWidget::getMinSpDefIv(int idx) const
{
  return m_spnMinSpDefIv[idx]->value();
}

int CommonPredictorFiltersWidget::getMinSpeedIv(int idx) const
{
  return m_spnMinSpeedIv[idx]->value();
}

int CommonPredictorFiltersWidget::getMinPowerHiddenPower() const
{
  return m_spnMinPowerHiddenPower->value();
}

bool CommonPredictorFiltersWidget::getEnableNatureFilter() const
{
  return m_chkEnableNatureFilter->isChecked();
}

QVector<bool> CommonPredictorFiltersWidget::getNatureFilters() const
{
  QVector<bool> naturesFilter;
  for (auto i : m_chkNatures)
    naturesFilter.append(i->isChecked());
  return naturesFilter;
}

bool CommonPredictorFiltersWidget::getEnableHiddenPowerTypesFilter() const
{
  return m_chkEnableHiddenPowerTypeFilter->isChecked();
}

QVector<bool> CommonPredictorFiltersWidget::getHiddenPowerTypesFilters() const
{
  QVector<bool> typesFilter;
  for (auto i : m_chkHiddenPowerTypes)
    typesFilter.append(i->isChecked());
  return typesFilter;
}

void CommonPredictorFiltersWidget::setMinHpIv(const int minHpIv)
{
  m_spnMinHpIv->setValue(minHpIv);
}

void CommonPredictorFiltersWidget::setMinAtkIv(const int minAtkIv, int idx)
{
  m_spnMinAtkIv[idx]->setValue(minAtkIv);
}

void CommonPredictorFiltersWidget::setMinDefIv(const int minDefIv, int idx)
{
  m_spnMinDefIv[idx]->setValue(minDefIv);
}

void CommonPredictorFiltersWidget::setMinSpAtkIv(const int minSpAtkIv, int idx)
{
  m_spnMinSpAtkIv[idx]->setValue(minSpAtkIv);
}

void CommonPredictorFiltersWidget::setMinSpDefIv(const int minSpDefIv, int idx)
{
  m_spnMinSpDefIv[idx]->setValue(minSpDefIv);
}

void CommonPredictorFiltersWidget::setMinSpeedIv(const int minSpeedIv, int idx)
{
  m_spnMinSpeedIv[idx]->setValue(minSpeedIv);
}

void CommonPredictorFiltersWidget::setMinPowerHiddenPower(const int minPowerHiddenPower)
{
  m_spnMinPowerHiddenPower->setValue(minPowerHiddenPower);
}

void CommonPredictorFiltersWidget::setEnableNatureFilter(const bool enableNatureFilter)
{
  m_chkEnableNatureFilter->setChecked(enableNatureFilter);
}

void CommonPredictorFiltersWidget::setNatureFilters(const QVector<bool> natureFilters)
{
  for (int i = 0; i < natureFilters.size(); i++)
    m_chkNatures[i]->setChecked(natureFilters[i]);
}

void CommonPredictorFiltersWidget::setEnableHiddenPowerTypesFilter(
    const bool enableHiddenPowerTypeFilter)
{
  m_chkEnableHiddenPowerTypeFilter->setChecked(enableHiddenPowerTypeFilter);
}

void CommonPredictorFiltersWidget::setHiddenPowerTypesFilters(
    const QVector<bool> hiddenPowerTypeFilters)
{
  for (int i = 0; i < hiddenPowerTypeFilters.size(); i++)
    m_chkHiddenPowerTypes[i]->setChecked(hiddenPowerTypeFilters[i]);
}
