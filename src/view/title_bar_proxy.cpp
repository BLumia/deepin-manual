/*
 * Copyright (C) 2017 ~ 2018 Deepin Technology Co., Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "view/title_bar_proxy.h"

#include "view/widget/title_bar.h"

namespace dman {

TitleBarProxy::TitleBarProxy(TitleBar* title_bar, QObject* parent)
    : QObject(parent),
      title_bar_(title_bar) {
  Q_ASSERT(title_bar_ != nullptr);

  connect(title_bar, &TitleBar::backwardButtonClicked,
          this, &TitleBarProxy::backwardButtonClicked);
  connect(title_bar, &TitleBar::forwardButtonClicked,
          this, &TitleBarProxy::forwardButtonClicked);
}

TitleBarProxy::~TitleBarProxy() {
}

void TitleBarProxy::setBackwardButtonActive(bool active) {
  title_bar_->setBackwardButtonActive(active);
}

void TitleBarProxy::setForwardButtonActive(bool active) {
  title_bar_->setForwardButtonActive(active);
}

}  // namespace dman