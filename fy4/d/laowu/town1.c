
inherit ROOM;

void create()
{
        set("short", "����֮��");
        set("long", @LONG
�ڷ⽭��ǰ���죬���ݵľ��������׼���õ�ľ�������ɻ����У�����������
ϵס���⽭�󣬸��ڽ����ϵ�ľ�ܶ������˸������������ڣ���ש���ߣ�����һ��
�����СС����ʽ�����ķ��ӣ����ڽ��ϸ���������
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"town",
]));
        set("outdoors", "laowu");
       set("objects", ([
        __DIR__"npc/guan" : 1,
	__DIR__"npc/pettrainer3" : 1,
                        ]) );


	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

