// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","��ʯ��");
  set("long",@LONG
�������۷�ң���Ӧ����һ����ģ�����Ħ��ʯ�̣����Զ�ݵ����룬���
��Ȼ����ǧ����ʷ�ˣ�������Ȼʯƺ֮�ϣ���������Ŀ��š���հ��������۾�����
�����ִ��綷��׭���汸���鷨�پ���������Ϊ�����ֱ��桱��������֮�ڡ���ǧ
����꣬����[33m����[32mֻ��һǧ�����ˣ���ȴ��Ȼ�޿ɱ��⡣
LONG
  );
  	set("exits",([
	"westdown" : __DIR__"doumu",
	"southup" : __DIR__"luohan",
               ]));
        set("objects", ([
        	BOOKS"skill/bolomiduo_50": 1,
                        ]) );
        set("outdoors", "taishan");
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",40);
	setup();
  	replace_program(ROOM);
}
