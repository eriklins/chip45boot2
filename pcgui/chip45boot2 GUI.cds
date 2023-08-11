<distribution version="10.0.0" name="chip45boot2 GUI" type="MSI">
	<prebuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></prebuild>
	<postbuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></postbuild>
	<msi GUID="{5B7AE49A-CA63-4A06-93D5-FCD5F10044C7}">
		<general appName="chip45boot2 GUI" outputLocation="d:\entwicklung\Projekte\Software\chip45boot2 GUI\trunk\cvidistkit.chip45boot2 GUI" relOutputLocation="cvidistkit.chip45boot2 GUI" outputLocationWithVars="d:\entwicklung\Projekte\Software\chip45boot2 GUI\trunk\cvidistkit.%name" relOutputLocationWithVars="cvidistkit.%name" upgradeBehavior="1" autoIncrement="true" version="1.9.17">
			<arp company="chip45 GmbH &amp; Co. KG" companyURL="http://www.chip45.com" supportURL="" contact="" phone="" comments=""/>
			<summary title="chip45boot2 GUI" subject="" keyWords="" comments="" author="Dr. Erik Lins, chip45 GmbH &amp; Co. KG"/></general>
		<userinterface language="English" showPaths="true" readMe="" license="">
			<dlgstrings welcomeTitle="chip45boot2 GUI" welcomeText=""/></userinterface>
		<dirs appDirID="100">
			<installDir name="[Start&gt;&gt;Programs]" dirID="7" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="[Program Files]" dirID="2" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="chip45boot2 GUI" dirID="100" parentID="2" isMSIDir="false" visible="true" unlock="false"/></dirs>
		<files>
			<simpleFile fileID="0" sourcePath="d:\entwicklung\Projekte\Software\chip45boot2 GUI\trunk\chip45boot2_gui.uir" relSourcePath="chip45boot2_gui.uir" relSourceBase="0" targetDir="100" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="1" sourcePath="d:\entwicklung\Projekte\Software\chip45boot2 GUI\trunk\cvibuild.chip45boot2_gui\Release\chip45boot2_gui.exe" targetDir="100" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/></files>
		<fileGroups>
			<projectOutput targetType="0" dirID="100" projectID="0">
				<fileID>1</fileID></projectOutput>
			<projectDependencies dirID="100" projectID="0"/></fileGroups>
		<shortcuts>
			<shortcut name="chip45boot2 GUI" targetFileID="1" destDirID="7" cmdLineArgs="" description="" runStyle="NORMAL"/></shortcuts>
		<mergemodules>
			<userMsms>
				<path>c:\program files (x86)\common files\merge modules\Microsoft_VC90_CRT_x86.msm</path>
				<path>c:\program files (x86)\common files\merge modules\policy_9_0_Microsoft_VC90_CRT_x86.msm</path>
				<path>c:\Program Files (x86)\Common Files\Merge Modules\Microsoft_VC90_ATL_x86.msm</path>
				<path>c:\Program Files (x86)\Common Files\Merge Modules\policy_9_0_Microsoft_VC90_ATL_x86.msm</path>
			</userMsms></mergemodules>
		<products/>
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
			<Project000 ProjectID="0" ProjectAbsolutePath="d:\entwicklung\Projekte\Software\chip45boot2 GUI\trunk\chip45boot2_gui.prj" ProjectRelativePath="chip45boot2_gui.prj"/></Projects>
		<buildData progressBarRate="10.410565383278927">
			<progressTimes>
				<Begin>0.000000000000000</Begin>
				<ProductsAdded>0.075513361797250</ProductsAdded>
				<DPConfigured>0.718600311318274</DPConfigured>
				<DPMergeModulesAdded>6.095254255618566</DPMergeModulesAdded>
				<DPClosed>6.890165271928301</DPClosed>
				<DistributionsCopied>7.000900943122994</DistributionsCopied>
				<End>9.605626238188407</End></progressTimes></buildData>
	</msi>
</distribution>
