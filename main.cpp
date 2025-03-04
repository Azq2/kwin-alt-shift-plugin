/*
    SPDX-FileCopyrightText: 2024 Vlad Zahorodnii <vlad.zahorodnii@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "eventlistener.h"

#include <KPluginFactory>

namespace KWin
{

class KWIN_EXPORT CtrlShiftLayoutSwitchFactory : public PluginFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID PluginFactory_iid FILE "metadata.json")
    Q_INTERFACES(KWin::PluginFactory)

public:
    explicit CtrlShiftLayoutSwitchFactory() = default;

    std::unique_ptr<Plugin> create() const override
    {
        return std::make_unique<EventListener>();
    }
};

} // namespace KWin

#include "main.moc"
