inherit ROOM;
void create()
{
    set("short", "����ʫ��");
    set("long", @LONG
����ʮ�أ�����𩾭������������������������г�һ�տ���ƽ�����ƣ�һ��
������ǰ���ʵ�Ϊ�˹������³����ѧ���ˣ��ڼ��ڽ����������׵㣬����һ����
��ʫ�磬�����µ�ʫ��ī�ͽ���ѧ�ʣ�ҲΪ�Ͼ��Ͽ����������ṩһ��ס����ʫ��
��ī��������ʱ�ڶ�����ν���²ſ�����֮�ء�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"jidijie",
	"up":	 __DIR__"clubpoem",
      ]));
    set("objects", ([
	__DIR__"npc/student" : 2,
      ]) );

    set("coor/x",-20);
    set("coor/y",60);
    set("coor/z",0);
    set("map","fynorth");
    setup();
}
