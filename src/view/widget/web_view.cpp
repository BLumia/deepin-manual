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

#include "view/widget/web_view.h"

#include <QContextMenuEvent>
#include <QMenu>

#include "view/widget/web_page.h"

namespace dman {

WebView::WebView(QWidget* parent) : QCefWebView(parent) {
}

WebView::~WebView() {

}

void WebView::contextMenuEvent(QContextMenuEvent* event) {
//  QMenu* menu;
//  const QString selected = page()->contextMenuData().selectedText();
//  if (!selected.isEmpty()) {
//    menu = new QMenu(this);
//    auto copy = page()->action(QWebEnginePage::Copy);
//    copy->setText(QObject::tr("Copy"));
//    menu->addAction(copy);
//    menu->popup(event->globalPos());
//  }
}

}  // namespace dman