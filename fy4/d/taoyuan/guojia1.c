inherit __DIR__"no_killing_place";
void create()
{
	set("short", "��լ");
	set("long", @LONG
ũ����Ϊ�ƾ�ȴ��ʰ��ʮ�ָɾ����룬�������ǽ�������Ž��ɫ�����ף���
�м�����⡣�������������������汻����ȫ�����濻�Ϸ���һ��С����ǽ������
�����߸ף������ƺ�װ����ʳ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
   		"east" : __DIR__"guojia",
   	]) );

	set("item_desc", ([
	"table": "С���Ϸ���һ��С�裬����װ�Ÿ�ʽ�����Ķ��ࡣ\n",
	"С��": "С���Ϸ���һ��С�裬����װ�Ÿ�ʽ�����Ķ��ࡣ\n",
	]) );

	set("objects", ([
		__DIR__"npc/guo": 1,
	]) );
	

	set("no_magic", 1);
   	set("outdoors","taoyuan");
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}

void init()
{
	::init();
	add_action("do_get", "get");
}																				
								
int do_get(string arg)
{
	if(!arg || arg != "����" && arg != "beans" && arg != "��") return 0;
}
									
