// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","�޺���");
  set("long",@LONG
̩ɽ����������ǵ����������Է�̴�������������̩ɽ���ۻ�������������
���֮ʿ���޺��¼�Ϊ�����Ӱ�֮�أ�����ɮ���ڴ˿������������ڳ�һ�޺�����
��Ϊ�ˣ��ն�������̩ɽ���£������ܻ����ڣ�����⴦���ڳ�Ϊ�޺��¡�
LONG
  );
  set("exits",([
	"northdown" : __DIR__"jingshi",
	"northup" : __DIR__"yingtao",
               ]));
        set("outdoors", "fengyun");
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",50);
	setup();
  	replace_program(ROOM);
}
