inherit ROOM;
void create()
{
    set("short", "ü���");
    set("long", @LONG
�����Ǹ��ص����裬����ˮ�Ǵӷ�ҶȪר�̼��������ĺ����������ɰ����
���ķ���Ҳ������ģ�ÿ����ĵ�һ�������������ġ������������Ĳ趼��
һ�ִ������������ԭ����һƷ���ѱ���Ǯ�ﹺ���£�����Ϊ��ü��ۡ�������Ц
�ݿ���Ĳ販ʿҲ�ؽ�������ȥ�ˣ�������˴��ľ�˵���������µĲ�����֡�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"yundoor",
	"up" :   __DIR__"yitea2",
      ]));
    set("objects", ([
	__DIR__"npc/teawaiter" : 1,
      ]) );

    set("coor/x",20);
    set("coor/y",-40);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}
