// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","��۷�");
  set("long",@LONG
˵�Ƿ壬��ʵ��һ���±ڣ���ǰһ��ƽ̹������ʯƺ������������Ŀ��Ħ��ʯ
��ʹ������������פ�㣬���С���̩ɽ�������ഫΪ���������飬����ǧ�ԣ�����
�����ۻ룬���鷨����һ�񣬱���Ϊ���Ժ���������֮��׳δ�м��ߡ���
LONG
  );
  set("exits",([
	"southwest" : __DIR__"bixia",
               ]));
        set("outdoors", "fengyun");
        set("objects", ([
        "/d/taoyuan/npc/rabbit": 2,
        ]) );

        
	set("coor/x",25);
	set("coor/y",25);
	set("coor/z",120);
	setup();
  	replace_program(ROOM);
}
