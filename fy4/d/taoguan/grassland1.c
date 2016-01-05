inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
�����Ƕ��͵�ɽ�£�����ˮ��¡¡����������ԶԶ��ȥ��һ����������ϱ�
�����𣬳��Ÿ�ʽ���������컨�ܣ���Щҩũ������һ��Ҳδ�ص���һ�������ҩ
�ݣ������ȴֻ����ͨ�ĵ�׺֮�
LONG
	);
	set("exits", ([ 
  		"east" : __DIR__"lake1",
  		"north" : __DIR__"grassland2",
  		"south" : __DIR__"hole4",
	]));
	 set("item_desc", ([
		"���컨��": "�����ҩ�ݣ����̲�ס��Ҫժ(pick)���ѡ�\n",
		"���ҩ��":"�����ҩ�ݣ����̲�ס��Ҫժ(pick)���ѡ�\n",
		"ҩ��":"�����ҩ�ݣ����̲�ס��Ҫժ(pick)���ѡ�\n",
		"flower":"�����ҩ�ݣ����̲�ס��Ҫժ(pick)���ѡ�\n",
		"herb":"�����ҩ�ݣ����̲�ס��Ҫժ(pick)���ѡ�\n"
	]));
	set("outdoors", "taoguan");
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
}


int init(){
	add_action("do_pick","pick");
}


int do_pick(string arg) {
	int num;
	object herb, me = this_player();
	if (arg == "flower" || arg == "herb" || arg == "���컨��" || arg =="���ҩ��" || arg == "ҩ��") {
		message_vision("��û��ע�⣬$N������ȥ���������ϵĻ��ݡ�\n",this_player());
	    tell_object(this_player(),"
��е����ӷ������ڰ���������˫�۾������㣡
����ϸ�ؿ���һ�����ܣ�ȴʲôҲû�У�\n");
		if (!this_player()->query("����A/����_ժ��")) {
			num = 1 + random(10);
	   		this_player()->set("����A/����_ժ��",num);
	   		log_file("riddle/FATE_LOG",
				sprintf("%s(%s) �õ�����A/����_ժ�� "+num+"�� %s \n",
						me->name(1), geteuid(me), ctime(time()) ));
		}
		return 1;
    }  
    return notify_fail("����ժʲô��\n");
}