// corpse.c

inherit ITEM;

int decayed;

void create()
{
        set_name("������Ѫ��ʬ��", ({ "bloody corpse","corpse" }) );
        set("long", "����һ��մ��Ѫ�۵�ʬ�壬��״�ֲ��������ӷ����Ͽ����ƺ������ŵĲ�ͷ��\n");
        set("unit", "��" );
        set("age", 20+ random(20));
	set("gender", "����");
	set("race", "����");
	set("victim_name", "��ͷ");
        decayed = 0;
        if( clonep(this_object()) ) call_out("decay", 120, 1);
}

int is_corpse() { return decayed < 2; }
int is_character() { return decayed < 1; }
int is_container() { return 1; }

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

void decay(int phase)
{
        decayed = phase;
        switch(phase) {
                case 1:
                        say( query("name") + 
"��ʼ�����ˣ�����һ�����ŵĶ����\n" );
                        switch(query("gender")) {
                                case "����":
                                        set_name("���õ���ʬ", ({ "corpse", 
"ʬ��" }) );
                                case "Ů��":
                                        set_name("���õ�Ůʬ", ({ "corpse", 
"ʬ��" }) );
                                default:
                                        set_name("���õ�ʬ��", ({ "corpse", 
"ʬ��" }) );
                        }
                        set("long",     
"���ʬ����Ȼ�Ѿ�����������һ��ʱ���ˣ���ɢ����һ�ɸ�ʬ��ζ����\n");
                        call_out("decay", 120, phase + 1);
                        break;
                case 2:
                        message("vision", query("name") + "���紵Ǭ�ˣ����һ�ߺ��ǡ�\n" ,environment());
                        set_name("һ�߿�Ǭ�ĺ���", ({ "skeleton", "����" }) 
);
                        set("long", "�⸱�����Ѿ���������ܾ��ˡ�\n");
                        call_out("decay", 60, phase + 1);
                        break;
                case 3:
                        message("vision", "һ��紵������" + query("name") + 
"���ɹǻҴ�ɢ�ˡ�\n" ,environment());
                        if( environment() ) {
                                object *inv;
                                int i;
                                
                                inv = all_inventory(this_object());
                                for(i=0; i<sizeof(inv); i++) 
{
	if((int) inv[i]->query("no_get") ||
	((int) !inv[i]->value() &&
	(int) !inv[i]->query("value")))
	destruct(inv[i]);
	else
	inv[i]->move(environment());
}
                        }
                        destruct(this_object());
                        break;
        }
}

object animate(object who, int level)
{
        object zombie;
        string name;
        int zskill;

        if( !environment() ) return 0;
        seteuid(getuid());
        zombie = new("/obj/npc/zombie");
        zombie->set_name( (string)query("victim_name") + "�Ľ�ʬ", ({ 
"zombie" }) );
        zombie->move(environment());
        zombie->animate(who, level);

        destruct(this_object());
        return zombie;
}
 
