inherit ROOM;
void create()
{
        set("short", "�ھ���Ժ");
        set("long", @LONG
�������ھֻ��������֮�࣬��Ϣ���ɵ�Ժ�ӡ�Ժ�ӵ�����������˵ļ��ż���
��ͣ������������ɹ�·��ġ�Ժ�ӵ���Χ�м���С�����ǹ�û�мҵ���������ס
�����ڡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"ghall",
  "east"  : __DIR__"gke1", 
  "north" : __DIR__"gke2",
  "south" : __DIR__"gke3",
]));
        set("item_desc", ([
                "bamboo": "��Щ��ͺ������Ų���������壩��\n",
                "���" : "��Щ��ͺ������Ų���������壩��\n",
                "�������" : "��Щ��ͺ������Ų���������壩��\n"
        ]) );

        set("outdoors", "fengyun");
        set("coor/x",30);
        set("coor/y",40);
        set("coor/z",-300);
        setup();
}

void init()
{

	add_action("do_move", "move");
}

int do_move(string arg)
{
object cock;
if ( !arg && arg != "bamboo" && arg != "���" && arg != "�������")
		return 0;
if( query("amount") > 10 ) return 0;
message_vision("$NŲ������ͣ�һֻ�޴����뼸�������Ű����˳�����\n", this_player());
cock = new(__DIR__"npc/hugecockr");
if(cock) cock->move(this_object());
add("amount",1);
return 1;
}

void reset()
{
	::reset();
	set("amount",0);
}
