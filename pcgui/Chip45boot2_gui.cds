<distribution version="9.0.1" name="Chip45boot2_gui" type="MSI">
	<prebuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></prebuild>
	<postbuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></postbuild>
	<msi GUID="{22825120-3AE2-4316-A27F-861FA63B339A}">
		<general appName="chip45boot2 GUI V0.9" outputLocation="b:\Projekte\Software\chip45boot2 GUI\trunk\cvidistkit.chip45boot2 GUI V0.9" relOutputLocation="cvidistkit.chip45boot2 GUI V0.9" outputLocationWithVars="b:\Projekte\Software\chip45boot2 GUI\trunk\cvidistkit.%name" relOutputLocationWithVars="cvidistkit.%name" autoIncrement="false" version="1.0.2">
			<arp company="chip45 GmbH &amp; Co. KG" companyURL="http://www.chip45.com" supportURL="" contact="Dr. Erik Lins, info@chip45.com" phone="" comments=""/>
			<summary title="" subject="" keyWords="" comments="" author=""/></general>
		<userinterface language="English" readMe="" license="">
			<dlgstrings welcomeTitle="chip45boot2 GUI" welcomeText=""/></userinterface>
		<dirs appDirID="101">
			<installDir name="[Start&gt;&gt;Programs]" dirID="7" parentID="-1" isMSIDir="true" visible="true"/>
			<installDir name="Chip45boot2_gui" dirID="100" parentID="7" isMSIDir="false" visible="true"/>
			<installDir name="[Program Files]" dirID="2" parentID="-1" isMSIDir="true" visible="true"/>
			<installDir name="Chip45boot2_gui" dirID="101" parentID="2" isMSIDir="false" visible="true"/></dirs>
		<files>
			<simpleFile fileID="0" sourcePath="b:\Projekte\Software\chip45boot2 GUI\trunk\chip45boot2_gui.uir" relSourcePath="chip45boot2_gui.uir" relSourceBase="0" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="1" sourcePath="b:\Projekte\Software\chip45boot2 GUI\trunk\chip45boot2_gui.exe" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/></files>
		<fileGroups>
			<projectOutput targetType="0" dirID="101" projectID="0">
				<fileID>1</fileID></projectOutput>
			<projectDependencies dirID="101" projectID="0"/></fileGroups>
		<shortcuts>
			<shortcut name="chip45boot2 GUI" targetFileID="1" destDirID="100" cmdLineArgs="" description="" runStyle="NORMAL"/></shortcuts>
		<mergemodules/>
		<products/>
		<runtimeEngine cvirte="true" instrsup="false" lvrt="false" analysis="false" netvarsup="false" dotnetsup="false" activeXsup="false" lowlevelsup="false" rtutilsup="false" installToAppDir="false"/>
		<advanced mediaSize="650">
			<launchConditions>
				<condition>MINOS_WIN2K_SP3</condition>
			</launchConditions>
			<includeConfigProducts>true</includeConfigProducts>
			<maxImportVisible>silent</maxImportVisible>
			<maxImportMode>merge</maxImportMode></advanced>
		<Projects NumProjects="1">
			<Project000 ProjectID="0" ProjectAbsolutePath="b:\Projekte\Software\chip45boot2 GUI\trunk\chip45boot2_gui.prj" ProjectRelativePath="chip45boot2_gui.prj"/></Projects>
		<buildData progressBarRate="0.028213718920825">
			<progressTimes>
					<Begin>0.000000000000000</Begin>
					<ProductsAdded>0.561999797821045</ProductsAdded>
					<DPConfigured>2.483999729156494</DPConfigured>
					<DPMergeModulesAdded>10.186999797821045</DPMergeModulesAdded>
					<DPClosed>13.514999866485596</DPClosed>
					<DistributionsCopied>13.733999729156494</DistributionsCopied>
					<End>35.443750000000001</End></progressTimes></buildData>
	</msi>
</distribution>
