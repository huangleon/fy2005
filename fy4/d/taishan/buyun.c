// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","�Ʋ���");
  set("long",@LONG
����̩ɽ��������֮�������ܷ��͵��֣�ɽ���վ����Ʋ��Ÿ�����磬������
�ٲ���й���ر���ÿ���꼾���٣����´��٣�������������ɫ��Ϊ׳�ۡ������ŷ�
�١����������ǧ������ک�費������ʤ֮�ء�
LONG
  );
  set("exits",([
	"down" : __DIR__"zhongtian",
	"westup" : __DIR__"aolai",
	"northup" : __DIR__"wusong",
               ]));
        set("outdoors", "fengyun");
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",70);
	setup();
  	replace_program(ROOM);
}
