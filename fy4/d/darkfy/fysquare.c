inherit ROOM;
void create()
{
        set("short", "���ƹ㳡");
        set("long", @LONG
̧ͷ��ȥ��������ѹ�ȥ�Ļ���������������ﾹȻ���͵���һ�����㳡������
�Ƿ�԰Լʮ�ɵ�ˮ�أ����еĽ��㻹�����е����Ρ���ɫ����������̵ĸ�Ƽ�໥��
ӳ������������Ŀ����ˮ�������ʯ���ϵľ�ͷ����Ȼ���������ķ���ÿ�����죬��
��������ӿ�����ף���ɵ�������ϡ����������֮�ᣬ����鳦�������˷ǣ���
��绪���꣬�����ǵ��ഺ�����룬����������ȴ�������᣿��Щ����˵������
������˶����Ƿ��Ѿ���ɢ�����������أ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"nwind1",
  "south" : __DIR__"swind1",
  "east" : __DIR__"ecloud1",
  "west" : __DIR__"wcloud1",
  	"down":	__DIR__"prep",
]));
        set("outdoors", "fengyun");
        set("resource/water",1);
        set("liquid/name","���̵�ˮ");
        set("liquid/type", "alcohol");
        set("liquid/drunk_apply",3);
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",-300);
        setup();
        // To "load" the board, don't ever "clone" a bulletin board.
        call_other( "/obj/board/fysquare_b", "???" );

}

void init()
{
        add_action("do_fillwater", "fillwater");
}
int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir;

        if( !arg || arg=="" ) return 0;

        if( arg=="skin" || arg=="wineskin" ) {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "��ˮ",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("���ˮ����װ������ˮ�� \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("��û��װˮ�Ķ�����....\n");
                        return 1;
                }
        }
        else {
                write("��Ҫ��ʲô�������ˮ��\n");
        }
        return 1;
}

