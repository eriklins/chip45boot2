<distribution version="10.0.0" name="custom specific" type="MSI">
	<prebuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></prebuild>
	<postbuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></postbuild>
	<msi GUID="{B2F78F06-B20F-4479-9BEE-AB0F1ED7C568}">
		<general appName="chip45boot2 GUI" outputLocation="d:\Entwicklung\Projekte\Software\chip45boot2 GUI\trunk\cvidistkit.chip45boot2 GUI" relOutputLocation="cvidistkit.chip45boot2 GUI" outputLocationWithVars="d:\Entwicklung\Projekte\Software\chip45boot2 GUI\trunk\cvidistkit.%name" relOutputLocationWithVars="cvidistkit.%name" upgradeBehavior="1" autoIncrement="true" version="1.0.0">
			<arp company="chip45 GmbH u. Co. KG" companyURL="http://www.chip45.com" supportURL="" contact="" phone="" comments=""/>
			<summary title="chip45boot2 GUI" subject="" keyWords="" comments="" author="chip45 GmbH u. Co. KG"/></general>
		<userinterface language="English" showPaths="true" readMe="" license="">
			<dlgstrings welcomeTitle="chip45boot2 GUI" welcomeText=""/></userinterface>
		<dirs appDirID="100">
			<installDir name="[Program Files]" dirID="2" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="chip45boot2_GUI" dirID="100" parentID="2" isMSIDir="false" visible="true" unlock="false"/>
			<installDir name="[Start&gt;&gt;Programs]" dirID="7" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="Hygrosens Instruments" dirID="101" parentID="7" isMSIDir="false" visible="true" unlock="false"/>
			<installDir name="Bootloader" dirID="102" parentID="101" isMSIDir="false" visible="true" unlock="false"/></dirs>
		<files>
			<simpleFile fileID="0" sourcePath="d:\Entwicklung\Projekte\Software\chip45boot2 GUI\trunk\chip45boot2_gui.uir" relSourcePath="chip45boot2_gui.uir" relSourceBase="0" targetDir="100" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="1" sourcePath="d:\Entwicklung\Projekte\Software\chip45boot2 GUI\trunk\cvibuild.chip45boot2_gui\Release\chip45boot2_gui.exe" targetDir="100" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/></files>
		<fileGroups>
			<projectOutput targetType="0" dirID="100" projectID="0">
				<fileID>1</fileID></projectOutput>
			<projectDependencies dirID="100" projectID="0"/></fileGroups>
		<shortcuts>
			<shortcut name="chip45boot2 GUI" targetFileID="1" destDirID="7" cmdLineArgs="" description="" runStyle="NORMAL"/></shortcuts>
		<mergemodules/>
		<runtimeEngine cvirte="true" instrsup="false" lvrt="false" analysis="false" netvarsup="false" dotnetsup="false" activeXsup="false" lowlevelsup="false" rtutilsup="false" installToAppDir="true"/>
		<advanced mediaSize="650">
			<launchConditions>
				<condition>MINOS_WINXP</condition>
			</launchConditions>
			<includeConfigProducts>true</includeConfigProducts>
			<maxImportVisible>silent</maxImportVisible>
			<maxImportMode>merge</maxImportMode>
			<custMsgFlag>false</custMsgFlag>
			<custMsgPath>c:\programme\national instruments\cvi2009\bin\msgrte.txt</custMsgPath>
			<signExe>false</signExe>
			<certificate></certificate>
			<signTimeURL></signTimeURL>
			<signDescURL></signDescURL></advanced>
		<Projects NumProjects="1">
			<Project000 ProjectID="0" ProjectAbsolutePath="d:\Entwicklung\Projekte\Software\chip45boot2 GUI\trunk\chip45boot2_gui.prj" ProjectRelativePath="chip45boot2_gui.prj"/></Projects>
		<buildData progressBarRate="4.983719730139591">
			<progressTimes>
				<Begin>0.000000000000000</Begin>
				<ProductsAdded>0.402409960764945</ProductsAdded>
				<DPConfigured>1.915548579820606</DPConfigured>
				<DPMergeModulesAdded>9.330077506817178</DPMergeModulesAdded>
				<DPClosed>12.657193909159732</DPClosed>
				<DistributionsCopied>12.789419515875313</DistributionsCopied>
				<End>20.065333809852717</End></progressTimes></buildData>
	</msi>
</distribution>
