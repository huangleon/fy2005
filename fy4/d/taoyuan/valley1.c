inherit ROOM;
void create()
{
    set("short", "ɽ��");
    set("long", @LONG
���ֵ��˴˴��𽥱��ϡ����������ǰ��Ȼ����һ��ǧ����䡢�����Ե�ɽ
�壬Χ��һ���Ĺȣ�����һ����̶��Ȫˮ�ӷ�䱼�����£�����й��ֱ����̶��
��ֻ��β�͵�Ұ�ã�����̶�����еĺ�ˮ���˴���������ʪ�������ķΣ�����ȴ
�������κ����Եĳ�·����������ֻ���Ĵ�[33mתת[32m���ˡ�
LONG
    );
    set("item_desc", ([
    	"��̶":  "��̶�������ף���ʱ����С��Խ��ˮ�档\n",
        "pond":  "��̶�������ף���ʱ����С��Խ��ˮ�档\n",
 		"תת":	 "תת��������Ӧ����ʲô�����أ�\n",
    ]));
    set("exits", ([ /* sizeof() == 4 */
   		"south" : __DIR__"taolin1",
	]));
    set("outdoors","taoyuan");
	set("coor/x",-40);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}
void init()
{
   add_action("do_around", "around");
}

int do_around(string arg)
{
   object me, room;
   int i;
   
   string *rooms = ({"valley", "valley1", "valley2", "valley3"});
   i = random(4);
   me = this_player();
   tell_object(me, "��ת��תȥ��Ҳû�ҵ����ڣ�������·����\n\n");
   room = find_object(__DIR__ + rooms[i]);
   if(!objectp(room)) room=load_object(__DIR__ + rooms[i]);
   me->move(room);

   return 1;
}

