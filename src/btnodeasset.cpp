#include "btnodeasset.h"

#include "btnodescriptable.h"
#include <QtCore/QStringList>
#include <QtCore/QUrl>

using namespace BehaviorTree;

class btNodeAsset::btNodeAssetPrivate
{
    public:
        btNodeAssetPrivate()
        {
			node = new btNodeScriptable();
        }
        
        ~btNodeAssetPrivate()
        {
			delete node;
		}
        
        btNodeScriptable * node;
		QUrl file;
		
};

BehaviorTree::btNodeAsset::btNodeAsset(QObject* parent)
	: GluonEngine::Asset(parent)
{
	d = new btNodeAssetPrivate();
}

BehaviorTree::btNodeAsset::~btNodeAsset()
{
	delete d;
}

void btNodeAsset::setFile(const QUrl& newFile)
{
    d->file = newFile;
}

const QStringList btNodeAsset::supportedMimeTypes() const
{
    QStringList mime;

    mime << "application/javascript";
    mime << "text/plain";

    return mime;
}

Q_EXPORT_PLUGIN2(gluon_plugin_asset_btnode, BehaviorTree::btNodeAsset)

#include "btnodeasset.moc"
