#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIG "��ԭһ����" NOR, ({ "jade" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѿ���ɫ�ĳ������������ᡣ\n");
        set("no_drop",1);
		set("no_get", 1);
		set("timestamp","tfhjfpo");	
		set("orig_name", "orig_name");
        set("owner","huac");
        set("rigidity",100);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}
	init_sword();
}

string query_save_file()
{
        string id;

        id = query("owner");
        if( !stringp(id) ) return 0;
        return sprintf(DATA_DIR "user/%c/%s/%s", id[0],id, id+"."+query("timestamp"));
}

int save()
{
        string file;
        string equipped;
        int result;
        if( stringp(file = this_object()->query_save_file()) ) {
                equipped = (string)query("equipped");
                delete("equipped");
                assure_file(file+ __SAVE_EXTENSION__);
                result = save_object(file,1);
                set("equipped",equipped);
                return result;
        }
        return 0;
}
int restore()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
        if(restore_object(file))
        {
                set_weight(query("weight"));
                return 1;
        }
        return 0;
}

