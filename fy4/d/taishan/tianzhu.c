// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
����̩ɽ�����壬Ҳ����߷壬���Ͻ�����ʹ�һ�����չ�ͤ������ͤ���ŵ�
��̨���ܻ��ƣ��������������������������ڴˡ����ն�����������ϼϦ�ա���
���ƺӽ���������ƺ����̡��Ĵ��澰�����۵ס�
LONG
  );
  set("exits",([
	"southdown" : __DIR__"bixia",
               ]));
        set("outdoors", "fengyun");
        set("objects", ([
       ]) );
	set("coor/x",20);
	set("coor/y",30);
	set("coor/z",130);
	setup();
  	replace_program(ROOM);
}
