#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");

	set("long", @LONG
���ƿ�ջ�Ĵ��ã����Ŵ��ľ�İ������ϻ�������ʯ��ǽ�Ϲ��Ÿ������ҵ���
�������ϰ����ļ��������ʻ�������һ�߽������ͻ�����Լ��������ֵط��Է���
�����ҡ�ƽʱ��ջ�ﴨ����Ϣ�ؽ����ľ���Щͦ��͹�������ֺ��ܡ�
LONG);

	set("type","house");
	set("exits",([
		"south":__DIR__"fyhotel",
		"north":__DIR__"fyyard",
	]) );
        set("indoors", "chenxiang");
	set("coor/x",20);
	set("coor/y",50);
	set("coor/z",0);
	set("item_desc", ([
                "picture": "һ�����ҵ��黭���ƺ�λ�ò��Ǻ�����\n",
                "�黭": "һ�����ҵ��黭���ƺ�λ�ò��Ǻ�����\n",
                "wall": "ѩ�׵�ǽ�Ϲ��ż������ҵ��黭�������黭�ƺ������ˡ�\n",
                "ǽ": "ѩ�׵�ǽ�Ϲ��ż������ҵ��黭�������黭�ƺ������ˡ�\n",
        ]) );
	set("objects",([
     		__DIR__"npc/fang":1,
    	]) );
	setup();
}

void init()
{
	add_action("do_pull", ({"pull","open"}));
}

int do_pull(string arg)
{
        object me;
        object fang;
        me=this_player();
        
        if(!arg || arg=="")
        {
			return 0;
        }
        if( arg == "picture" || arg == "�黭")
        {
        	if(fang =present("fang longxiang",this_object()))
        	{
        		message_vision(HIR"$N��$n���һ���������ӣ��Ҵ����ӵ����⣬��������\n"NOR, fang,me);
        		fang->kill_ob(me);
        		me->kill_ob(fang);
        		return 1;
        	}
        	else
        	{
        		message_vision("$N����ǽ�ϵ��黭��������һ�����š�\n", me);
        		if( !query("exits/east") ) 
        		{
        			set("exits/east", __DIR__"stoneroom");
        			call_out("close_path", 2);
        		}
        		return 1;
        	}
        }
        else
        {
                write("�㲻���Դ�"+arg+"\n");
                return 1;
        }
}

void close_path()
{
        if( !query("exits/east") ) return;
        message("vision","�黭���˻���������ס�˰��š�\n",this_object() );
        delete("exits/east");
}

int valid_leave(object me, string dir)
{
	object fang;
        if( 	userp(me) && dir=="north"
        	&&	present("fang longxiang", this_object())
        	&& !REWARD_D->check_m_success(me,"���ϰ���"))
        {        	
		return notify_fail("���������ֵ�סȥ·������ǿͷ������ǲ�Ҫ������˵ĺã�\n");
	}
	return 1;
}
