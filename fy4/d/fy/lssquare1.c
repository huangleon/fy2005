inherit ROOM;
void create()
{
    set("short", "���߹㳡");
    set("long", @LONG
����ԭ���Ǹ��ܿ��������֣�����ǰͻȻһҹ֮�䱻��Ϊƽ�أ�Ȼ��ͬ��ͻȻ
ð��������������Ϻ������̷����е������������Ⱥ��������̵��ϲ���Ҳ�д���
���հ�ߺ���ţ����Ƿ�����ɸ⣬�ඹ�̶�С��⡣������±�˵ġ����Ƶġ�����
����Ƥ�ġ�����ը����ġ���ɽ������ͷ�ġ�����������ġ��������㵰�۵ġ���
��Ѽ���յġ�����ͷ�⡢�л��յġ���������ġ��������Եġ���������֭�ġ���
�ƺ���������ó����̷�ȫ�����������ֱ���������е���Ἧ��Ҫ���֡�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"southwest" : __DIR__"yulong2",
	"east" : __DIR__"lssquare2",
	"north" : __DIR__"zuisheng",
	"west" : __DIR__"seven",
      ]));
    set("objects", ([
	//        __DIR__"npc/wanfan" : 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",120);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}


