// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","��Ů��");
  set("long",@LONG
��Ů�����������Զ������λ����Ů��������裬�ݴ������������Ů������
����ĵط����ۻ��ɽ�������ر�����ᣬ������һĨ��Ȫ������Ϫ����ǳ������
���Ļ��䣬����Ů��Χ��һ�������Զ����С��ͷ����Ů���������ǳЦ����������
����컯ʵ�ڲ�ͬ���졣
LONG
  );
  set("exits",([
	"eastdown" : __DIR__"wusong",
	"westup" : __DIR__"longjiao",
               ]));
        set("objects", ([
        __DIR__"npc/pettrainer4" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",90);
	setup();
  	replace_program(ROOM);
}
