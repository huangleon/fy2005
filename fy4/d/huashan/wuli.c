
inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�����Ϊ��ɽ���յ�һ�أ��˴��������ڣ�������Ԩ��������Ҫ��������Ϊ
�ӱ��ַ˻������������գ���ʯΪ�ƣ��������أ���һ�򵱹أ����Ī��������
�أ�����ǰ�б��ǻ�ɽ��ʯ�š�
LONG
        );
    set("exits", ([ 
  		"eastdown" : __DIR__"yuquan",
  		"southeast" : __DIR__"shaluo",
	]));
  	set("objects", ([
		__DIR__"npc/explorer" : 1,
	]));    
    set("outdoors", "huashan");

	set("coor/x",-15);
	set("coor/y",10);
	set("coor/z",0);
	setup();
    replace_program(ROOM);
}

