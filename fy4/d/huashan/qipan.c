
inherit ROOM;

void create()
{
        set("short", "����̨");
        set("long", @LONG
�·嶥��ԭ��ƽ̹�����к��������嶥����̨��̨�Ͻ�����ͤһ����ͤ���ù�
Χ��һ�̡�̨�治���������֣�̽ͷ��������ֻ��������������ãã���붫���
һ����ɽ��������
LONG
        );
    set("exits", ([ 
  		"north" : __DIR__"yaozi",
	]));
	set("objects", ([
                __DIR__"npc/gongye.c" : 1,
	            __DIR__"npc/crow.c" : 1,
       ]) );

   
    set("outdoors", "huashan");

	set("coor/x",-1);
	set("coor/y",-60);
	set("coor/z",33);
	setup();
    replace_program(ROOM);
}

