// annie 07.2003
// dancing_faery@hotmail.com

inherit ROOM;
void create()
{
    set("short", "���߼�");
    set("long", @LONG
�����Ƿ��Ƴ��������ϱ������У����������̼�ÿ��������������˳���
��������Ʒ��һЩ���ز�Ʒ���⣬�Ӹ������������챦����������ü�����������
�µ����飬Ҳ�в�������ĺ�Ѫ�������������պ�һ����˿����弰��֬ˮ�ۣ�
���в�Զǧ�Զ��������̴��Ӵ������ĸ���ϡ������⡣�����ڶ��̼��Ƽ�
�˴���һЩ�ڵ�����Ҳͨ���������ó�ף���������ϴǮ��
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"lssquare2",
      ]));
    set("objects", ([
	__DIR__"npc/mai" : 1,
	__DIR__"npc/zhen" : 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",160);
    set("coor/y",60);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
