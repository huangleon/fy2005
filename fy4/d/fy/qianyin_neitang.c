// inn.c

inherit ROOM;


void create()
{
    set("short", "��������");
    set("long", @LONG
�߽��������ã�ǽ�Ϲ������������һ���˼�ֻ��һ������Ψ�����̹�
���������������ϰ��̰�Ŀ��Լ�һ���ˡ������±�һ����������һ�����൱����
�ڵĳ���������һ�����ʷ�������λ�ӡ�
LONG
    );

    set("exits", ([
	"east"      : __DIR__"qianyin",
      ]) );
    set("objects", ([
//	__DIR__"npc/hockowner" : 1,
        __DIR__"npc/tatoo": 1,
//add by ldb  ��Ϊ������٣���������Ӹ��NPC�߶���Ҫ��ʱ��û����������Ķ������Զ���⡣ 
      ]) );


    set("coor/x",-110);
    set("coor/y",-20);
    set("coor/z",0);
    set("map","fywest");
//    replace_program(ROOM);
    setup();
}
