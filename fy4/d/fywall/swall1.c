inherit ROOM;
void create()
{
    set("short", "�ϳ�ǽ");
    set("long", @LONG
�����ĳ�ǽ�ָ��ֺ񣬸���һ�ְ�ȫ�ĸо���ң�����⣬��ɫ����Ұһ������
һ����СС��ũ�����ǵ��ĵ�׺�ſ�����Ұ������ʱ������������Ϧ��б�գ���
��ʤ�ա�Զ�������Ⱥɽ�������˸е�����׳�ۡ�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"secorner",
	"west"  : __DIR__"supgate", 
      ]));
    set("outdoors", "fengyun");
    set("coor/x",150);
    set("coor/y",-300);
    set("coor/z",30);

    set("objects", ([
	__DIR__"npc/f" : 1,
      ]) );

    setup();
    replace_program(ROOM);
}
