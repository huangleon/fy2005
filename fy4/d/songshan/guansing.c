// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����̨");
        set("long", @LONG
����������������̨��ַ��λ�ڵǷ�����ʮ���ﴦ���ܹ��⾰�㷢Դ�ڴˣ�
�������������У����������Ӱ���Զ���ʱ���ڡ���ȷ�����ܴ���������
��̨�ڹ磬����ߣ�һӦ��ȫ��
LONG
        );
        set("exits", ([ 
  "northdown" : __DIR__"shizong",
]));
        set("objects", ([
                __DIR__"npc/zha" : 1,
       ]) );
        set("outdoors", "songshan");
	set("coor/x",30);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
