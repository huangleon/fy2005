//Sinny@fengyun 2003
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
    set("short", "�ҽ���");
    set("long", @LONG
·�����ˣ��ɸ��ӵ��±̺���ɳ��Ҳ��Զ�����ϰ��ƹ³ǣ������ƶ���ƺ�����
��ߣ���ν�ð��Ƶ����֮ݼ�����ڣ�Ҷ�³������ڴˣ�������־��

                           ��
                           ��
                           ��
                           ��

LONG
    );
    set("exits", 
      ([ 
	"northdown" : __DIR__"jianlin",
	"southwest" : __DIR__"hillroad",
      ]));
    set("objects", 
      ([ 
	__DIR__"npc/guard2" : 1,
	__DIR__"npc/guard3" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",15);
    set("coor/y",-80);
    set("coor/z",20);
    setup();
}


int valid_leave(object me, string dir)
{
    object *inv, ob;
    int i;

    if( userp(me) && me->query("class")!="baiyun") {
	if( dir == "northdown"  && ob=present("swords man", this_object())) {
	    inv = all_inventory(me);
	    for(i=0; i<sizeof(inv); i++) {
		if((int)(inv[i]->query("weapon_prop")) && (int)(inv[i]->query("equipped")))
		    return notify_fail(ob->name()+"���˹��ֵ�����ȡ���彣��\n");
	    }
	}
    }

    return 1;
}
