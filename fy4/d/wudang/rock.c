
inherit ROOM;

void create()
{
	set("short", "�⽣ʯ");
	set("long", @LONG
С·�����һ�������ƶ���Сͤ�ӣ��ɹ�������Ϣ��ͤ��ǰ��һ����˸ߵľ�
ʯ���Ͽ̡��⽣ʯ���������֡������˵�����壭Ľ����ˮ���ô������ָ��д��
�Ա�ʾ���䵱���𾴺���Ľ�����������ڴ�Ҫ��������ı��У��ſ���ɽ��
LONG
	);
	set("exits", ([
		"northdown" : __DIR__"xuanwumen",
		"southup" : __DIR__"road3",
	]));
	set("objects", ([
		__DIR__"npc/taoist1" : 1,
	]));
	set("outdoors", "wudang");
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",-20);
	setup();
}

int valid_leave(object me, string dir)
{
        object *inv, ob;
        int i;

        if( userp(me)&& me->query("class")!="wudang") {
        	if( dir == "southup"  && ob=present("xu", this_object())) {
                	inv = all_inventory(me);
                	for(i=0; i<sizeof(inv); i++) {
                        	if((int)(inv[i]->query("weapon_prop")) && (int)(inv[i]->query("equipped")))
                        	return notify_fail(ob->name()+"����˵����ʩ�����ɴ�������ɽ���\n");
             		}
        	}
        }

        return 1;
}
