// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","�����");
  set("long",@LONG
�����Ĵ����ƺ��Ƿǳ����������ţ���Ȼֻ��һСС��¥��������ǧ����ǰ��
�������ľשʯ������ɽ֮�У�ʵ���ǲ���˼�飬��ľ��������Բ����ԣ�������
���������Զ�ĸ������ֱ�������ŵİض��������ﾡ���۵ף�ɽ·���࣬�Ű�����
��ӣ�֦Ҷ���죬������䣬���붴��������������������С�
LONG
  );
  set("exits",([
	"down" : __DIR__"doumu",
	"up" : __DIR__"butian",
	"northeast" : __DIR__"yanghuang",
               ]));
        set("objects", ([
        __DIR__"npc/xue" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",40);
	setup();
  	replace_program(ROOM);
}
