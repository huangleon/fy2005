// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","��ɽ");
  set("long",@LONG
ɽ���绢���۰�һ�����ش�̩ɽ���࣬������ĸ�أ��ݴ��˵����ػ���ĸ����
��������Զ��[33mɽ��[32m��������צ���������ˣ��鶯���ѣ��ý����ף������人�꣬��
��ɽ��ȼ磬��Ȼ֮������֮��Ҳ��
LONG
  );
  	set("exits",([
	"west" : __DIR__"wangmu",
               ]));
        set("objects", ([
        	BOOKS"skill/tigerstrike_100" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);

}
