// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "ӳ������");
    set("long", @LONG
��ɽ�������������һ�ο�����ˮ����ϲɲʱ��������ͷ��������������
һ�����������ˮ�����ֱ�����Ľ�֮���븹�С�һ����䣬ֻ������ӯӯ��
ˮͻ�����˲������������������ģ�ֻ����ˮ�����ã���ӳ�ŵ�ٲȻ�Ƿ�
�Ƴ��ڹ⾰��
LONG
NOR
        );
	set("objects", ([
	]));
	set("item_desc", ([
	"��ˮ":"����Խ���ӳ��������ħ�����ۿ�����Ҫ֪��������(scry)��\n",
	"��":"����Խ���ӳ��������ħ�����ۿ�����Ҫ֪��������(scry)��\n"

	]) );
	set("exits",([
  		"northdown" : __DIR__"peak7",
  		"westdown" : __DIR__"peakx",
	]) );

	set("outdoors", "cyan");

	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",80);
	setup();
}

void init() {
	add_action("do_scry","scry");
	add_action("do_whisper","whistle");
}


int do_whisper()
{
	object me = this_player();
	object yr;
	if (REWARD_D->riddle_check(me,"̽��׷Դ") != 1 && REWARD_D->riddle_check(me,"̽��׷Դ") != 7 )
		return 0;
	if (present("shanliu yinluren",this_object()))
		return 0;
	message_vision("$N����ش��������ڣ�����\n",me);
	yr=new(__DIR__"npc/shanliu1");
	yr->move(this_object());

	if (REWARD_D->riddle_check(me,"̽��׷Դ") != 7 )
		yr->hi(me);
	else
		yr->hi2(me);
	return 1;
}


// inventory messages.
string inventory_look(object obj, int flag) {
    string str, desc;
    object me, left, right;

    str = obj->short();
    if(obj->query("equipped")) {
        if(!desc = obj->query("armor_worn")) {
            if(!desc=obj->query("weapon_wielded")) {
                desc = "��";
            } else {
                me = environment(obj);
                left = me->query_temp("left_hand");
                right = me->query_temp("right_hand");
                if(obj == left && obj == right) {
                    desc = "˫��" + desc + "��";
                } else if(obj == right) {
                    desc = "����" + desc + "��";
                } else {
                    desc = "����" + desc + "��";
                }
            }
        }
        str = desc + str;
    } else if(!flag) {
        str = (environment(obj)->is_character() && !environment(obj)->is_corpse() ? 
                "����" : "  ") + str;
    } else {
        return 0;
    }
    
    return str;
}

int do_scry(string arg)
{
	object me = this_player();
	object obj;

    string str, limb_status, pro;
    mixed *inv;
    mapping my_fam, fam;

	if (!arg)
		return notify_fail("����Ѱ��ʲô��\n");

	if (me->query_temp("timer/big_cmd")+2 > time())
		return notify_fail("ӳ�������е�ˮ����û�г���ƽ�����ٵ�һ�Ȱɡ�\n");
	else
		me->set_temp("timer/big_cmd",time());

	me->add("sen",-30);

	obj = find_living(arg);
	if (!obj)
		return notify_fail("ӳ������ˮ��������ã�����������ƽ����\n");
	if (!environment(obj))
		return notify_fail("ӳ������ˮ��������ã�����������ƽ����\n");
	if (userp(obj))
		return notify_fail("ӳ������ˮ��������ã�����������ƽ����\n");
	 if (obj->query("race")=="Ԫ��")
		return notify_fail("ӳ������ˮ��������ã�����������ƽ����\n");


	message_vision("ӳ������ˮ��������ã�����������ƽ����\n",me);
	message_vision("���е�ӳ����"+obj->name()+"����Ӱ��\n",me);

	str = obj->long();
    pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

    if((string)obj->query("race")=="����" && intp(obj->query("age")))
    {
        if(userp(obj))
		{
            str +=  sprintf("%s��������%s�����%s�ˡ�\n", pro, 
                    chinese_number(obj->query("age") / 10 * 10), obj->query("national"));
		    } else 
			{
            str += sprintf("%s������Լ%s���ꡣ\n", pro, 
                    chinese_number(obj->query("age") / 10 * 10));
			  }
    }

    // current kee status.
    if(obj->query("max_kee")) {
        str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_kee") * 100 
                / (int)obj->query("max_kee")) + "\n";
    }
    
    // inventory message.
    if(obj->query("race") == "����") {
        str += pro + (obj->is_naked() ? "�������塣\n" : "");
    }
    inv = all_inventory(obj);
    if(sizeof(inv)) {
        inv = map_array(inv, "inventory_look", this_object(), (obj == me || obj->is_corpse()) ? 0 : 1 );
        inv -= ({ 0 });
        if(sizeof(inv)) {
            str += sprintf("%s\n", implode(inv, "\n  "));
        }
    }
    // tatoo print
    if (obj->query_temp("body_print") ) str += obj->query_temp("body_print")+ "\n";

    
    // send out message
    message("vision", str + "\n", me);
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


