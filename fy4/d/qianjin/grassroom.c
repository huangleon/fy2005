inherit ROOM;
void create()
{
	object con, item;
        set("short", "����");
        set("long", @LONG
����ݸ���ȴ��ˬ������̨���������й�һ������С������һ�Ű�ľ��齡�
����֮�࣬ɫɫ�ྻ����ɨ�õ������˺����������л����������У�ʮ�ַ�ï��
�����ʱ��л���˽ڳ��������������У����Ǻ��ϰ˽���ס����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"yue",
  "south" : __DIR__"shui",
  "east" : __DIR__"bridge1",
  "west" : __DIR__"bridge2",
]));
        set("objects", ([
        __DIR__"obj/flower" : 1,
	__DIR__"obj/pin" :1,
	__DIR__"npc/qianjinwaiter" :1,
                        ]) );
	set("coor/x",-40);
	set("coor/y",10);
	set("coor/z",0);
        setup();
	con = present("flower", this_object());
	item= present("pin", this_object());
	item->move(con);
}

void init()
{
 
if(!random(1000)) call_out("lucky", 1, this_player());

}

int lucky(object me)
{

message_vision("$N���󿴵����л������ж�����������\n", me);
return 1;
}

void reset(){
        object con,item;
        ::reset();
        con = present("flower", this_object());
	if(!present("pin", this_object()) && !present("pin", con)){
                item = new(__DIR__"obj/pin");
                if(objectp(item)){
                        item->move(con);
                }
        }
        return;
}       
