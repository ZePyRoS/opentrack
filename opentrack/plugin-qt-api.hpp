#pragma once

#include <QString>
#include <QFrame>
#include <QIcon>

struct Metadata
{
public:
    virtual QString name() = 0;
    virtual QIcon icon() = 0;
    virtual ~Metadata() {}
};

// XXX TODO get rid of QString/QFrame to fix ABI woes
// will lead plugins from different C++ runtimes working -sh 20141004

struct IFilter
{
public:
    virtual ~IFilter() {}
    virtual void filter(const double *input, double *output) = 0;
};

struct IFilterDialog : public QWidget
{
    virtual ~IFilterDialog() {}
    virtual void register_filter(IFilter* filter) = 0;
    virtual void unregister_filter() = 0;
};

struct IProtocol
{
public:
    virtual ~IProtocol() {}
    virtual bool correct() = 0;
    virtual void pose(const double* headpose) = 0;
    virtual QString game_name() = 0;
};

struct IProtocolDialog : public QWidget
{
    virtual ~IProtocolDialog() {}
    virtual void register_protocol(IProtocol *protocol) = 0;
    virtual void unregister_protocol() = 0;
};

struct ITracker
{
public:
    virtual ~ITracker() {}
    virtual void start_tracker(QFrame* frame) = 0;
    virtual void data(double *data) = 0;
};

struct ITrackerDialog : public QWidget
{
    virtual ~ITrackerDialog() {}
    virtual void register_tracker(ITracker *tracker) = 0;
    virtual void unregister_tracker() = 0;
};
