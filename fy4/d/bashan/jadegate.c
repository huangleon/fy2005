// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "����ʯ��");
    set("long", @LONG
һ�����ѵ�С·��ϡ���������۵�������������ȥ����ǰ����������һ��
�޴��ʯ�ţ����ɶ�ߣ����ɶ��ϸ��֮�£�����˾޴���صĴ��ž���������
���һ��������ʯ�̣������������������ܹ��ƶ���ʯ��һ������һ�����񱮣���
�ϵ�������ʫ�ġ�
LONG
    );
    set("exits",([
	"east" : __DIR__"maze1/exit",
	"northup" : "/d/potboil/41",
      ]) );
    set("objects", ([
	__DIR__"mazenpc/gatekeeper" :1,
	__DIR__"mazenpc/gatekeeper2" :1,
      ]) );
    set("item_desc", ([
	"����": "�������ϵ�������ʫ�ģ�\n\n"CYN"����������������\n���������ԡ�����\n��������������ī\n���������ա�����\n��������Ҷ������\n���������桡����\n���������ᡡ����\n\n"NOR"����������С�ף��ƺ����Բ�(insert)��ʲô������\n",
	"��": "�������ϵ�������ʫ�ģ�\n\n"CYN"����������������\n���������ԡ�����\n��������������ī\n���������ա�����\n��������Ҷ������\n���������桡����\n���������ᡡ����\n\n"NOR"����������С�ף��ƺ����Բ�(insert)��ʲô������\n",
      ]) );

    set("outdoors", "bashan");

    set("coor/x",-20);
    set("coor/y",0);
    set("coor/z",0);
    setup();
}

void init()
{
    add_action("do_insert","insert");
    add_action("do_i","go");
}

int do_i(string arg)
{
    if (arg == "west")
	tell_object(this_player(),"�������ĳ�·������ʯ����ס�ˡ�\n");
    return 0;
}

int do_insert(string arg)
{
    object env = this_object(),ob,me = this_player();
    if (!arg)
	return notify_fail("��Ҫ��ʲô��\n");
    if (!ob=present(arg,me))
	return notify_fail("��Ҫ��ʲô��\n");
    if ( crc32(crypt("a"+ob->query_weight()+"n","n"+crc32(ob->query_weight()+"")+"ie")) != 1026565555)
	return notify_fail("���������޷������롣\n");
    if (crc32(crypt(ob->name(),crc32(ob->name()))) != -2090929369)
	return notify_fail("���������޷������롣\n");
    if (query("already_closed"))
	return notify_fail("����ʯ���ϵ�С�����Ѿ����ж����ˡ�\n");
    // snicker...�²¿�����ʲô��
    message_vision(WHT"$N��һ"+ob->query("unit")+ob->name()+WHT"���������ʯ���ϵ�С���С�\n"NOR,me);
    add("ins",1);
    set("item_desc", ([
	"����": "�������ϵ�������ʫ�ģ�\n\n"CYN"����������������\n���������ԡ�����\n��������������ī\n���������ա�����\n��������Ҷ������\n���������桡����\n���������ᡡ����\n\n"NOR"������һ��С�ף��ƺ����Բ�(insert)��ʲô������\n",
	"��": "�������ϵ�������ʫ�ģ�\n\n"CYN"����������������\n���������ԡ�����\n��������������ī\n���������ա�����\n��������Ҷ������\n���������桡����\n���������ᡡ����\n\n"NOR"������һ��С�ף��ƺ����Բ�(insert)��ʲô������\n",
      ]) );
    if (query("ins") == 2)
    {
	set("already_closed",1);
	message_vision(HIG"ֻ��һ���������죬����ʯ�Ż����Ļ���һ�ߣ�����\n"NOR,me);
	set("exits/west", __DIR__"restroom");
	set("item_desc", ([
	    "����": "�������ϵ�������ʫ�ģ�\n\n"CYN"����������������\n���������ԡ�����\n��������������ī\n���������ա�����\n��������Ҷ������\n���������桡����\n���������ᡡ����\n"NOR,
	    "��": "�������ϵ�������ʫ�ģ�\n\n"CYN"����������������\n���������ԡ�����\n��������������ī\n���������ա�����\n��������Ҷ������\n���������桡����\n���������ᡡ����\n"NOR,
	  ]) );
    }
    destruct(ob);
    return 1;
}


int valid_leave(object me, string dir)
{
    if( dir == "west")
    {
	add("ins",-1);
	if (query("ins") < 0)
	{
	    delete("exits/west");
	    message_vision(CYN"$N��Ҫ�ٲ���������һ����Ƶ���������������ʯ�ź��һ��������ȥ��\n"NOR,me);
	    return notify_fail("��������Ѿ�û�г�·�ˡ�\n");
	}
	return 1;
    }
    return 1;
}




/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

