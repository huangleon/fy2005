
// ΪʲôҪ��scroll������point? ΪʲôҪ����n���ſ���һ���Ķ���������һ����һ�㣿
// ����Ŀ����Ȼ������ҿ��Բ������ܵĽ��л��ཻ����

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("����", ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",YEL"һ������˿�\n"NOR);
                set("value", 1000);
                set("material", "paper");
        }
}

void init()
{
   	add_action("do_read","read");
}
    
int do_read(string arg)
{
	object me,*inv;
	mapping data;
	int lev,req,i,count;
	string t;

	if (!arg)
		return 0;

	count = 0;

	me = this_player();

	if (present(arg,me)!=this_object())
		return 0;

	t = query("teaching");

	lev = ANNIE_D->check_ability(me,t);
	if (lev >= 10)
		return notify_fail("���ż������Ѿ��������˼��£���Ҳ���ܳ����ˡ�\n");
	req = lev + 1;

	inv = all_inventory(me);
	for (i=0; i<sizeof(inv); i++)
		if (inv[i]->query("teaching") == t)
			count++;
	if (count < req)
		return notify_fail("�����������ż��ɣ��������������"+chinese_number(req)+"��"+query("name")+"��\n");

   	if( me->query("potential") - me->query("learned_points") < req*req*req*50 )
       	return notify_fail("�����������ż��ɣ����������ӵ��"+chinese_number(req*req*req*50)+"��Ǳ�ܡ�\n");

	me->add("learned_points",req*req*req*50);
	message_vision(HIW"$NС������ش򿪾��ᡣ\n"NOR,me);
	tell_object(me,HIC"�����ž����ϵķ������������������ǰ������������\n"NOR);
	tell_object(me,HIC"һ����Ĺ��������ѧ��Ϊ������һ��¥��\n"NOR);
	message_vision(HIG"Ƭ�̣�$N���еľ����������䣬�����һ��Ʈɢ�ڷ��С�\n"NOR,me);
	me->perform_busy(1);

	ANNIE_D->improve_ability(me,t);

	count=0;
	for (i=0; i<sizeof(inv); i++)
		if (inv[i]->query("teaching") == t && count < req-1 && inv[i] != this_object())
		{
			destruct(inv[i]);
			count++;
		}
	
	destruct(this_object());
	return 1;
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
