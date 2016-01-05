#include <ansi.h>

inherit ROOM;
string *names=({
	__DIR__"maze2",
	__DIR__"maze1",
	__DIR__"maze4",
	__DIR__"maze7",
} );
void create()
{
	set("short", "��ѩ����");
	set("long", @LONG
��������˴��СС������ɫɫ�ı������Ǵ���Ȼ��������Ĳ�����Ʒ������
����ȥ��ȫ���Ǳ�ѩ�����硣���ָ����ı����ֲ���ĩ�˱������棬��̬��������
����Ⱥɽ���������ľ��ۡ��ߴ����׵ı�Ģ����ϸϸ�ı���֧�ţ�ҡҡ��׹����ǽ
����ֱ������޴�����磬������η�����������Ե������������εض����е���
�����ı������е����ɲ��¥�����б��������š������������ȵȡ�����Ȼ�ı���
���磬���Ǿ�������Ĳ��ϵ��ܶ��ɣ��γɺ�������˥����
LONG
	);
        set("outdoors", "guanwai");
	set("coor/x",-40);
	set("coor/y",-80);
	set("coor/z",100);
	setup();
}
void reset()
{
	int i,j;
	string temp;
	::reset();
	for (i=0;i<=3;i++)
	{
		j=random(4);
		temp=names[j];
		names[j]=names[i];
		names[i]=names[j];
		names[i]=temp;
	}
	set("exits", ([
		"north" : names[0],
		"south" : names[1],
		"east" : names[2],
		"west" : names[3],
	]));
}

int valid_leave(object me, string dir)
{
	object *inv;
        object ob;
        int i;
        int dam_gin,dam_sen,dam_kee;
        dam_gin = (int) me->query("max_gin")/10;
        dam_sen = (int) me->query("max_sen")/10;
        dam_kee = (int) me->query("max_kee")/10;

	if( userp(me) && dir == "south" )
	{
		inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                	if(inv[i]->query("bigcloth") && (int)inv[i]->query("equipped"))
	                        return 1;
	        }
                message_vision(HIW"ɽ��Խ��Խ�󣬼��������ѩ������һ�����$Nÿһ�缡��......\n$N������Ĵ��˸���ս��\n"NOR,me);
                if((int)me->query("kee")<dam_kee ||(int)me->query("kee")<dam_kee||(int)me->query("kee")<dam_kee) {
                	me->unconcious();
                }
                else {
                	me->receive_damage("kee", dam_kee);
	                me->receive_damage("gin", dam_gin);
	                me->receive_damage("sen", dam_sen);
	                me->set_temp("last_damage_from","�ڹ����ѩ���缢�����ȶ�����\n");
	        }
        }
        else if( userp(me) )
        {
        	inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                	if(inv[i]->query("bigcloth") && (int)inv[i]->query("equipped"))
	                        return 1;
        	switch ( random(10) )
        	{
			case 1:			
				if((int)me->query("gin")<dam_gin) {
                			return notify_fail(HIW"���󺮷������߹ι�����������֫��ľ���粽���С�\n"NOR);
					me->unconcious();
					break;
               			}
               			else {
               				me->receive_damage("gin", dam_gin);
               				me->set_temp("last_damage_from","�ڹ����ѩ���缢�����ȶ�����\n");
					me->start_busy(5);
					return notify_fail(HIW"���󺮷������߹ι�����������֫��ľ���粽���С�\n"NOR);
					break;
				}
			case 2:
				me->set_temp("disable_inputs",1);
				me->set("disable_type",HIW "<������>"NOR);
				me->set_temp("is_unconcious",1);
				me->start_call_out( (: call_other, __FILE__, "remove_frozen",me :),random(20) );
				return notify_fail(HIW"������ű�ѩ������ǵؾ��ǰ�ããһƬ��������ѩ���ƺ���ѪҺ\n��������...\n"NOR);
				break;
		}
	}
	return 1;
}

void remove_frozen(object me)
{
	me->delete("disable_type");
	me->delete_temp("disable_inputs");
	me->delete_temp("is_unconcious");
	if(!me->is_ghost())
	message_vision(HIR "\n\n$N�������һ�������������ӻ�ѩ�������˳�������\n\n"NOR, me);
}