inherit ROOM;
void create()
{
    set("short", "����ǽ");
    set("long", @LONG
�����ĳ�ǽ�ָ��ֺ񣬸���һ�ְ�ȫ�ĸо���ң�����⣬��ɫ����Ұһ������
һ����СС��ũ�����ǵ��ĵ�׺�ſ�����Ұ������ʱ������������Ϧ��б�գ���
��ʤ�ա�Զ�������Ⱥɽ�������˸е�����׳�ۡ�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"eupgate",
	"south"  : __DIR__"secorner", 
      ]));
    set("outdoors", "fengyun");
    set("coor/x",300);
    set("coor/y",-150);
    set("coor/z",30);

    set("objects", ([
	__DIR__"npc/k" : 1,
      ]) );

    setup();
    replace_program(ROOM);
}
