inherit ROOM;

void create()
{
    set("short", "ç�ֱ�Ե");
    set("long", @LONG
�����е�·Խ��Խխ�����Ե���֦Խ��Խ�ܣ�������������������Ҳ��ð߰�
��㡣é�ݽ��񣬹�ľ������·�����𡣴����ķ�ҲԽ�������䳱ʪ��Զ�����ֵ�
������м�ֻ������ͺӥ������˺���ѷεĽ���������ë����Ȼ��·������ŤŤ��
���Ÿ�ʾ��[33m�����޳�û����ȥ�޻ء�[32m
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"groupn2",
	"north" : AREA_FYCYCLE"fyroad0",
      ]));
    set("outdoors", "manglin");
    set("NONPC",1);
    set("coor/x",50);
    set("coor/y",-40);
    set("coor/z",20);
    setup();

}
