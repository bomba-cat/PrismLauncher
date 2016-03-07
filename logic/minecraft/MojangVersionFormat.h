#pragma once

#include <minecraft/VersionFile.h>
#include <minecraft/Library.h>
#include <QJsonDocument>

#include "multimc_logic_export.h"

class MULTIMC_LOGIC_EXPORT MojangVersionFormat
{
public:
	// version files / profile patches
	static VersionFilePtr versionFileFromJson(const QJsonDocument &doc, const QString &filename);
	static QJsonDocument profilePatchToJson(const ProfilePatchPtr &patch);

	// libraries
	static LibraryPtr libraryFromJson(const QJsonObject &libObj, const QString &filename);
	static QJsonObject libraryToJson(Library *library);

private:
	static QJsonDocument versionFileToJson(VersionFilePtr patch);

	static MojangAssetIndexInfoPtr assetIndexFromJson (const QJsonObject &obj);
	static MojangDownloadInfoPtr downloadInfoFromJson (const QJsonObject &obj);
	static MojangLibraryDownloadInfoPtr libDownloadInfoFromJson (const QJsonObject &libObj);
	static QJsonObject assetIndexToJson (MojangAssetIndexInfoPtr assetidxinfo);
	static QJsonObject libDownloadInfoToJson (MojangLibraryDownloadInfoPtr libinfo);
	static QJsonObject downloadInfoToJson (MojangDownloadInfoPtr info);
};
