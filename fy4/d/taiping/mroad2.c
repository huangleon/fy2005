inherit ROOM;
void create()
{
        set("short", "С��");
        set("long", @LONG
�ֵ����������˷����������������ľ�����һ������Ҷ��糺�������������
�糯¶���������ݵ���֬��С��������֬����֮�£�����������ļ��ˡ�С������
��һ������ͷ��լ�ӣ�������һ��С������ľ������Χ�˸�դ������������ȥ
ȥ���˲��࣬ÿ���˵����ź��񶼲�̫�¾ɡ�
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"house1",
		"east": __DIR__"droad0",
		"southwest": __DIR__"mroad3",
		"northeast": __DIR__"mroad1",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		    
	]));
	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",0);
	set("map","taiping");
	setup();

}
