
inherit ROOM;

void create()
{
        set("short", "��ޱ��");
        set("long", @LONG
�˴���һ��������̵��˹�ɽ������������������ݱ�أ���������һ��
ʯ�����Ի������ڰ����Ŷ��ڣ������������¿������ڶ���������Ĵ���������
�������������ڹ����ű���̫�ʴ��������������ӵ��������������
LONG
        );
    set("exits", ([ 
  		"westdown" : __DIR__"zhuyu",
	]));
	set("objects", ([
		__DIR__"obj/tstone" : 1,
		__DIR__"obj/bamboo" : 1,
		__DIR__"npc/bonze" : 1,
	]));
    set("indoors", "huashan");
	
	set("coor/x",15);
	set("coor/y",10);
	set("coor/z",-20);
	setup();
    replace_program(ROOM);
}

