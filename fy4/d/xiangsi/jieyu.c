// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "������");
    set("long", @LONG
����ǰȥ��ֻ��ɽ��������խ���������һ��ֻ�а�������ΡΡ�յ�
�����óȻ̤���յ���Ī˵ת��������˫�㲢��Ҳ���������ܡ�̽ͷ��խ
��������ȥ��ֻ������Σ�����������ɣ�����ʧ��׹�£��ٻ�ͷ���ǰ���֮
��
LONG
    );
    set("objects", ([
	//		__DIR__"npc/ghost" : 1,
      ]));
    set("exits",([
	"east" : __DIR__"wuzhang",
	"west" : "/d/bashan/enterance",
	"southup" : "/d/bashan/hf",
      ]) );
    
    set("outdoors", "xiangsi");
    
    set("objects", ([
	__DIR__"npc/ghost" : 1,
      ]));
    
    set("coor/x",-10);
    set("coor/y",0);
    
    set("boss_room",24);
    
    set("boss",__DIR__"npc/ghostmaster");
    set("ph",__DIR__"npc/ghost");
    
    set("coor/z",0);
    setup();
}


int ph_here()
{
    object env,*inv;
    int i;
    env = this_object();
    inv = all_inventory(env);
    for (i=0;i<sizeof(inv) ; i++)
	if (inv[i]->query("real_boss") || inv[i]->query("real_ph"))	// ��Ȼ��
	    return 1;
    
    return 0;
}

void reset()
{
    object npc;
    
    if (!ph_here())
    {
	if (!random(query("boss_room")))	
	{
	    npc = new(query("boss"));
	    npc->move(this_object());
	}
	else
	{
	    npc = new(query("ph"));
	    npc->move(this_object());
	}
    }
    ::reset();
}

